from flask import Flask,render_template ,request,jsonify
from flask_cors import CORS
from flask_sslify import SSLify
app = Flask(__name__)
CORS(app)
sslify = SSLify(app)
app.config['SSLIFY_CERT_PATH'] = '/etc/letsencrypt/live/exsinnot.com/cert.pem'
app.config['SSLIFY_KEY_PATH'] = '/etc/letsencrypt/live/exsinnot.com/privkey.pem'
@app.route("/upload", methods=["POST"])
def upload():
    if 'image' in request.files: #save img
        image_file = request.files['image']
        if image_file.filename != '':
            image_file.save('received_image.jpg')
            return 'Image received and saved successfully.'
    return 'Image upload failed.'

@app.route('/Update', methods=['POST'])
def update():    
    data = request.json
    user = data.get('username')

    response_data = {
        'status': 'false'
    }
    return jsonify(response_data)


@app.route('/voteqr', methods=['GET'])
def voteqr():
    ip_address = request.remote_addr
    value = request.args.get('team')
    if "203.xxx.xxx.xxx" == ip_address:
        return render_template('vote.html',team=value)
    else:
        print(ip_address)
        return render_template('ERROR.html',err=1)



if __name__ == '__main__':
    app.run(host='0.0.0.0',port=443, ssl_context=(app.config['SSLIFY_CERT_PATH'], app.config['SSLIFY_KEY_PATH']),debug=True)
