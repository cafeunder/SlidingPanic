#ifndef IMAGEMANAGER_DEF
#define IMAGEMANAGER_DEF

#include <map>
#define GETIMAGE(name) (ImageManager::GetInstance()->GetImage(name))

class ImageManager {
private:
	ImageManager();
	std::map<const char*, int> image_map;

public :
	int GetImage(const char* name);

	static ImageManager* GetInstance() {
		static ImageManager instance;
		return &instance;
	}
};

#endif