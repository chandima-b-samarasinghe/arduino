#define ENCODER_PIN 3
#define WHEEL_CIRCUMFERENCE 20

int encoder_current,encoder_previous;
double encoder_distance;

void setupEncoder(){
	pinMode(ENCODER_PIN,INPUT);
	encoder_previous=analogRead(ENCODER_PIN);
	encoder_distance=0;
}

double convertToDistance(int encoder_value){
	return WHEEL_CIRCUMFERENCE*((double)encoder_value/1023);
}

void encode(){//not yet written completely
	encoder_current=analogRead(ENCODER_PIN);
	encoder_distance+=convertToDistance(encoder_current-encoder_previous);
	encoder_previous=encoder_current;
}

//without using interrupts
void setup(){
	setupEncoder();
}

void loop(){
	encode();
}
