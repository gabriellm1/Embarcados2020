#!/usr/bin/env python3
from flask_cors import CORS, cross_origin
import os
from flask import Flask, jsonify
import subprocess

app = Flask(__name__)
CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'
# POST para selecionar a chave
@app.route("/read", methods=['GET'])
@cross_origin()
def readLED():
        process = subprocess.Popen(['./../scripts/read_switch'], stdout=subproc>
        stdout = process.communicate()[0]
        print ('STDOUT:{}'.format(stdout))
        if(int(stdout)):
                return {'botao':1}
        else:
                return {'botao':0}
