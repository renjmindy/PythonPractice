from flask import Flask
import os

application = Flask(__name__)

@application.route('/')
def hello_world():
    db_name = os.environ['DATABASE_NAME']
    return "Hello World. My database name is " + db_name

if __name__ == '__main__':
    application.run()