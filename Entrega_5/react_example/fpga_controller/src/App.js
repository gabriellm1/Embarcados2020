import logo from './logo.svg';
import React from 'react';
import './App.css';




class App extends React.Component {
   state = { botao: null };

   toogleLED = () => {
      const headers = { 'Content-Type': 'application/json' }
      fetch('http://192.168.0.45:5000/blink', { headers })
   }

   readBT = () => {
    
        const headers = { 'Content-Type': 'application/json' }
        let res = 0;
        fetch('http://192.168.0.45:5000/read', { headers })
        .then(response => {return response.json()})
        .then((data) => {
          if (data.botao == 1){this.setState({ botao: "Ativado" })}
          else{this.setState({ botao: 'Desativado' })}
                              
        })
  }


  render(){
  return (
    <div class="App-header">
    <h1>Entrega 5 - Embarcados Avançados</h1>
    <h3>Gabriel Monteiro</h3>
    <button class='led' onClick={this.toogleLED}>Ative o LED</button>
    <button class='bt' onClick={this.readBT}>Leitura do botão</button>
    <div>{this.state.botao}</div>
  </div>
  );
  }
}

export default App;
