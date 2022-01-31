from flask import Flask, request
app = Flask(__name__)

@app.route('/')
def hello_world():
    return "Hello World"

@app.route('/spamorham', methods=['GET', 'POST'])
def spamorham():
    message = request.args.get("message")
    return message

if __name__ == '__main__':
    app.run()