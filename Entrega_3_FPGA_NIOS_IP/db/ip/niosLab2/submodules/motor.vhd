library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.numeric_std.all;
use work.all;

entity motor is
    generic (
        LEN  : natural := 4
    );
    port (
        -- Gloabals
        clk                : in  std_logic                     := '0';             
        reset              : in  std_logic                     := '0';             

        -- I/Os
        stepmotor_phases  : out std_logic_vector(3 downto 0);

        -- Avalion Memmory Mapped Slave
        avs_address     : in  std_logic_vector(3 downto 0)  := (others => '0'); 
        avs_read        : in  std_logic                     := '0';             
        avs_readdata    : out std_logic_vector(31 downto 0) := (others => '0'); 
        avs_write       : in  std_logic                     := '0';             
        avs_writedata   : in  std_logic_vector(31 downto 0) := (others => '0')
    );
end entity motor;

architecture rtl of motor is

component stepmotor is
    port (
        -- Gloabals
        clk   : in  std_logic;

        -- controls
        en      : in std_logic;                     -- 1 on/ 0 of
        dir     : in std_logic;                     -- 1 clock wise
        vel     : in std_logic_vector(1 downto 0);  -- 00: low / 11: fast

        -- I/Os
        phases  : out std_logic_vector(3 downto 0)
    );
    end component stepmotor;

signal reg_settings, reg_vel :  std_logic_vector(31 downto 0);
signal stepmotor_en, stepmotor_dir : std_logic;
signal stepmotor_vel : std_logic_vector(1 downto 0);

begin
  process(clk)
  begin
    if(rising_edge(clk)) then
        if(reset = '1') then
            reg_settings <= (others => '0');
            reg_vel <= (others => '0');
        else
            if(avs_write = '1') then
                case avs_address is
                    when "0000" => reg_settings <= avs_writedata;
                    when "0001" => reg_vel <= avs_writedata;
                    when others => null;
                end case;
            end if;
            
            if (avs_read = '1') then
                case avs_address is
                    when "0000" => avs_readdata <= reg_settings;
                    when "0001" => avs_readdata <= reg_vel;
                    when "0010" => avs_readdata <= x"AAAA555";
                    when others => avs_readdata <= (others => '0');
                end case;
            end if;
        end if;
    end if;         
  end process;

  stepmotor_en <= reg_settings(0);
  stepmotor_dir <= reg_settings(1);
  stepmotor_vel <= reg_vel(1 downto 0);



  u1 : stepmotor port map (clk, stepmotor_en, stepmotor_dir, stepmotor_vel, stepmotor_phases);

end rtl;
