#ifndef _CAMRECORDER_RECORDER_H
#define _CAMRECORDER_RECORDER_H

#include <opencv2\opencv.hpp>
#include <boost\filesystem.hpp>

#include <string>

class Recorder {
public:
	Recorder();
	Recorder(const std::string& root, const std::string& videoname);
	Recorder(const std::string& root, const std::string& videoname, const cv::Size& size, bool saveVideo, bool saveImages);
	~Recorder();

	void writeFrame(const cv::Mat& image);
	bool isLoaded();
private:
	bool loaded;
	bool saveImages;
	bool saveVideo;
	int frameCount;
	std::string root;
	std::string videoname;
	std::string imagesPath;
	cv::VideoWriter writer;
	cv::Size size;
};

#endif
