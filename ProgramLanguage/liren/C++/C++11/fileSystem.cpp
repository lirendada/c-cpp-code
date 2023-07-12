#include "Test.h"

size_t FileSystem::numDisks() const
{
	return 10;
}

FileSystem& tfs()
{
	static FileSystem fs;
	return fs;
}