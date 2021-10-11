#include "app.h"

void mcb(int event,int x,int y,int flags,void* userData){
	std::cout << "mX: " << x << '\n';
}

App::App(std::string windowName) : camera_(std::move(windowName)){
	cv::setMouseCallback("Dale",mcb,NULL);
}

void App::run(){
	while(true){
		updateDeltaTime();
		camera_.updateFrame();

		controlMotor();

		camera_.drawROIs();
		camera_.show();
		if(handleKey() == KeyCode::EXIT)
			break;
		Rod rod = camera_.getRod();
		std::cout << "position: (" << rod.getLeftPoint().x << ", " <<
			 rod.getLeftPoint().y  << ")\n";
	}
}

void App::controlMotor(){
	switch(key_){
		case 'a':
		std::cout<< "AAAAAAAAAAAAAAAAAAAAAAAAAA";
		motor_.move(-5);
		break;
		case 'd':
		motor_.move(5);
		break;
		case 'q':
		motor_.move(-10);
		break;
		case 'e':
		motor_.move(10);
		break;
		default:
		motor_.move(0);
	}
}

void App::updateDeltaTime(){
	auto duration = std::chrono::steady_clock::now() - timePoint_;
	deltaTime_ = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	timePoint_ = std::chrono::steady_clock::now();
}

int App::handleKey(){
	key_ = cv::waitKey(16);
	return key_;
}
