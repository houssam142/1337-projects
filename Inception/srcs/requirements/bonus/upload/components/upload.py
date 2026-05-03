import os
import mysql.connector
from werkzeug.utils import secure_filename
from flask import Flask, request
from html import escape

app = Flask(__name__)
UPLOAD_DIR = "/uploads"

def read_secret(path):
    with open(path, "r") as f:
        return f.read().strip()

db = mysql.connector.connect(
    host=os.environ.get("DB_HOST"),
    user=os.environ.get("DB_USER"),
    password=read_secret("/run/secrets/db_password"),
    database=os.environ.get("DB_DATABASE")
    )


@app.route("/upload/", methods=["POST"])
def upload():
    file = request.files["file"]
    user_id = request.form.get("user_id", 0)
    
    filename = secure_filename(file.filename)
    filepath = os.path.join(UPLOAD_DIR, filename)
    file.save(filepath)

    cursor = db.cursor()
    cursor.execute(
            "INSERT INTO uploads (filename, filepath, user_id) VALUES (%s, %s, %s)",
            (filename, filepath, user_id)
            )
    db.commit()
    return "upload successful"


@app.route("/files", methods=["GET"])
def files():
    cursor = db.cursor()
    cursor.execute("SELECT filename, filepath, user_id FROM uploads")
    files = cursor.fetchall()

    html = "<h1>Uploaded Files</h1>"

    for filename, path, user_id in files:
        html += f"<h3>{filename} (user {user_id})</h3>"
        try:
            with open(path, "r", errors="ignore") as file:
                content = file.read(10000)

            html += f"""
            <pre style="background:#111;color:#0f0;padding:10px;">
{escape(content)}
            </pre>
            """

        except Exception as e:
            html += "<p>Cannot display file</p>"

        html += "<hr>"

    return html


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=9443)
