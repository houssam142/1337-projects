from flask import Flask, request

app = Flask(__name__)
@app.route("/upload/", methods=["POST"])
def upload():
    file = request.files["file"]
    file.save("/uploads/" + file.filename)
    return "OK"

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=9443)
