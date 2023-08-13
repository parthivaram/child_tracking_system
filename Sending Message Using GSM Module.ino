void setup()
{
  //Push buttons as INPUT pins
  pinMode(PA_13,INPUT);       
  //The baud rate of GSM Module is set
  Serial1.begin(9600);    
  delay(1000);
}


void loop()
{
  delay(100);
  //Reading the status of push button
  int a = digitalRead(PA_13);         
  //If push button is  
  if (a == 1)                         
  {
     SendMessage();
  }
}

//Function to send message
void SendMessage()      
{
  delay(1000);
  //Seting the GSM Module in Text Mode
  Serial1.println("AT+CMGF=1");    
  delay(1000);  
  //The number to which SMS is to be given is set
  Serial1.println("AT+CMGS=\"+91XXXXXXXXXX\"\r"); 
  delay(1000);
  //The SMS text wanted to send is set
  Serial1.println("Hi Circuit Digest from GSM Module"); 
  delay(100);
  //ASCII code of CTRL+Z
  Serial1.println((char)26);
  }
}