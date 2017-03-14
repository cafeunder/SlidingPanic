#include <DxLib.h>
#include "ImageManager.h"

const char* image_list[] = {
	"mychar",
	0
};

ImageManager::ImageManager() {
	char buf[256];
	for (int i = 0; image_list[i] != 0; i++) {
		sprintf(buf, "data\\image\\%s.png", image_list[i]);
		this->image_map.insert(std::map<const char*, int>::value_type(
			image_list[i],
			LoadGraph(buf)
		));
	}
}

int ImageManager::GetImage(const char* name) {
	return this->image_map[name];
}