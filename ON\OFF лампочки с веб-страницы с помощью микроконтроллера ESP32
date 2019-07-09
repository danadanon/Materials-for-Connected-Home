//Board: ESP32
//Language: JavaScript
//Software: ESPRuino WEB IDE
//by Dana&Alua

var wifi = require("Wifi");

wifi.startAP('EspruinoAP', { 
  password: '0123456789', 
  authMode: 'wpa2' },function() {
  console.log(`AP started`);
});

function onPageRequest(req, res) {
  var b = url.parse(req.url, true);
  
  if (b.pathname=="/") {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write("<H1><a href=\"/on\"><button><center>ON</center></button></a></H1>");
    res.end("<H1><a href=\"/off\"><button><center>OFF</center></button></a></H1>");
  } else if (b.pathname=="/on") {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write("<a href=\"/on\"><button><svg></svg><center>ON</center></button></a>");
    res.end("<H1><a href=\"/off\"><button><center>OFF</center></button></a></H1>");
    //res.end("Enable");
    digitalWrite(D16, false);
  } else if (b.pathname=="/off") {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write("<H1><a href=\"/on\"><button><center>ON</center></button></a></H1>");
    res.end("<H1><a href=\"/off\"><button><center>OFF</center></button></a></H1>");
    //res.end("Disable");
    D16.write(true);
  } else {
    res.writeHead(404, {'Content-Type': 'text/plain'});
    res.end("404: Page "+b.pathname+" not found");
  }
}
require("http").createServer(onPageRequest).listen(80);
