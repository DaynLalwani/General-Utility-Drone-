#import <BMP390.h> 
#import <MPU9250.h>

int SDA_PIN = 21;
int SCL_PIN = 22;

int RXD = 16;// i too lazy to open the schematic , put the correct pin here
int TXD = 15;//same with dis
int GPS_BAUD = 9600;

HardwareSerial gpsSerial(2);

MPU9250 IMU(Wire, 0x68);
int status
string vals = ""
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  BMP390 bmp(SDA_PIN, SCL_PIN);
  while (!Serial && millis() < 5000); //Wait for Serial
  bmp3_data bmp_data = bmp.get_bmp_values();//get vals
  //checks if BMP vals are readable
  if (bmp_data.success) {
    Serial.println("BMP390 Init!");
  } else {
    Serial.println("BMP390 Init Failed :(");
  }
  status = IMU.begin();
  if (status < 0){
    Serial.println("IMU Init Failed")
    Serial.println(status)
  }

  gpsSerial.begin(GPS_BAUD,SERIAL_8N1,SERIAL_8N1,RXD,TXD);
  Serial.println("GPS serial started :)")
}

void loop() {

  IMU.readSensor()
  vals += "Ax:"+String(IMU.getAccelX_mss())+"Ay:"+String(IMU.getAccelY_mss())+"Az:"+String(IMU.getAccelZ_mss())+"Gx:"+String(IMU.getGyroX_rads())+"Gy:"+String(IMU.getGyroY_rads())+"Gz:"+String(IMU.getGyroZ_rads())+"Mx:"+String(IMU.getMagX_uT())+"My:"+String(IMU.getMagY_uT())+"Mz:"+String(IMU.getMagZ_uT())+"Timu"+String(IMU.getTemperature_C())
  // put your main code here, to run repeatedly:
  bmp3_data data = bmp.get_bmp_values();
  if (data.success){
    vals += " Tbaro:"+String(data.temperature)+" P(hPa):"+String(data.pressure /100);
  }
  if (gpsSerial.available() > 0){
  char gpsData = gpsSerial.read();
  Serial.println(gpsData)
  }
  Serial.println(vals);
  vals = "";
}
