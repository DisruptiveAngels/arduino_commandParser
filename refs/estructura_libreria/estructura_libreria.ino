
//Facil
void getPixel(){
  //WHOAMI pendiente
  int x = parser.getInt();
  int y = parser.getInt();

  float temp = camara.readPixel(x, y);

  parser.response(cmdPix, temp);
}

//Ideal
void getPixel(int x, int y){
  float temp = camara.readPixel(x, y);
  return temp;
}

//Simple
Command cmdPix("pix", getPixel);
//Ideal
Command cmdPix("pix", getPixel, int, int, float);


CommandParser parser(9600, P_P, NONE);
CommandParser parser(115200, P_P, CHECKSUM);
CommandParser parser(9600, BUS, CRC);
CommandParser parser(9600, st='$',del=',', fn='\n', P_P, NONE);


void setup() {
  parser.addcmd(cmdPix);
  parser.name("INO_IR");
  parser.begin();
}

void loop() {
  parser.parse(); //Do your thing!
}
