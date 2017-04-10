#include <jni.h>
#include <MsHook.h>

#define hook(a,b,c) MSHookFunction((void*)&a,(void*)&b,(void**)&c)

struct Player
{
	int GetWingTime();
};

static int (*_GetWingTime)(Player *);
static int GetWingTime(Player *p)
{
	_GetWingTime(p);
	
	return 99999999;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	hook(Player::GetWingTime,GetWingTime,_GetWingTime);
	
	return JNI_VERSION_1_6;
}
