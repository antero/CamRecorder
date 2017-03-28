#include <recorder.h>

using namespace cv;
using namespace std;
namespace fs = boost::filesystem;

Recorder::Recorder() :
	Recorder(string("."), string("new video"))
{}

Recorder::Recorder(const string& root, const string& videoname) :
	Recorder(root, videoname, Size(0,0), false, true)
{}

Recorder::Recorder(const string& root, const string& videoname, const Size& size, bool saveVideo, bool saveImages) :
	root(root),
	videoname(videoname),
	size(size),
	saveVideo(saveVideo),
	saveImages(saveImages),
	loaded(false)
{
	if (!fs::exists(root)) {
		fs::create_directories(root);
	}

	if (saveImages) {
		imagesPath = root + string("\\") + videoname + string("\\");
		fs::create_directories(imagesPath);
	}

	if (saveVideo) {
		string videopath = root + string("\\") + videoname + string(".avi");
		writer.open(videopath, VideoWriter::fourcc('L', 'A', 'G', 'S'), 30, size);
		loaded = writer.isOpened();
	} else {
		loaded = true;
	}
}
	

Recorder::~Recorder()
{
	if (saveVideo) {
		writer.release();
	}
}

void Recorder::writeFrame(const Mat& image)
{
	frameCount++;

	if (saveVideo) {
		writer.write(image);
	}

	if (saveImages) {
		char filename[1024];
		sprintf_s(filename, 1024, "%s%05d.png", imagesPath.c_str(), frameCount);
		imwrite(filename, image);
	}
}

bool Recorder::isLoaded()
{
	return loaded;
}
