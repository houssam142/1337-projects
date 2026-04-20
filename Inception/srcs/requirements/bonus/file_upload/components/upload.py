from flask import Flask, request

app = Flask(__name__)
@app.route("/upload/", method=["POST"])
def upload():
    file = request.files["file"]
    file.save("/uploads" + file.filename)
    return "OK"
