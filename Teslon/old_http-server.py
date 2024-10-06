#Outdated version of the server, moved to nodejs



#import RPi.GPIO as GPIO
import os
from http.server import BaseHTTPRequestHandler, HTTPServer

host_name = '10.3.141.1'  # IP Address of Raspberry Pi
host_port = 8000


#def setupGPIO():
#    GPIO.setmode(GPIO.BCM)
#    GPIO.setwarnings(False)
#
#    GPIO.setup(22, GPIO.OUT)
#    GPIO.setup(27, GPIO.OUT)

class MyServer(BaseHTTPRequestHandler):

    def do_HEAD(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def _redirect(self, path):
        self.send_response(303)
        self.send_header('Content-type', 'text/html')
        self.send_header('Location', path)
        self.end_headers()

    def do_GET(self):
        html = '''
<html>
    <head>
        <title>TESLON-CONTROLL</title>
    </head>
    <body style="width:960px; margin: 20px auto;">
        <form action="/" method="POST">
            <input type="submit" name="submit" value="LEFT">
            <input type="submit" name="submit" value="RIGHT">
            <input type="submit" name="submit" value="Off">
        </form>
    </body>
</html>
        '''
        self.do_HEAD()
        self.wfile.write(html.format().encode("utf-8"))

    def do_POST(self):

        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length).decode("utf-8")
        post_data = post_data.split("=")[1]

#        setupGPIO()

#       if post_data == 'LEFT':
#            GPIO.output(22, GPIO.HIGH)
#        elif post_data == 'RIGHT':
#            GPIO.output(27, GPIO.HIGH)
#        else:
#            GPIO.output(22, GPIO.LOW)
#            GPIO.output(27, GPIO.LOW)

        self._redirect('/')  # Redirect back to the root url


# # # # # Main # # # # #

if __name__ == '__main__':
    http_server = HTTPServer((host_name, host_port), MyServer)
    print("Server Starts - %s:%s" % (host_name, host_port))

    try:
        http_server.serve_forever()
    except KeyboardInterrupt:
        http_server.server_close()
