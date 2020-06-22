#if 0
#!/bin/sh
cc main.c ~/.steam/ubuntu12_32/steam-runtime/usr/lib/x86_64-linux-gnu/libvulkan.so.1
LD_LIBRARY_PATH=~/.steam/ubuntu12_32/steam-runtime/usr/lib/x86_64-linux-gnu ./a.out
echo $?
exit
#endif

unsigned vkCreateInstance(void * createInfo, void * allocator, void * outInstance);
unsigned vkEnumeratePhysicalDevices(void * instance, unsigned * outPhysicalDevicesCount, void * outPhysicalDevices);

int main() {
  struct {
    unsigned sType;
    void *   pNext;
    unsigned flags;
    void *   applicationInfo;
    unsigned enabledLayerNamesCount;
    char **  enabledLayerNames;
    unsigned enabledExtensionNamesCount;
    char **  enabledExtensionNames;
  } info = {};
  info.sType = 1;
  void * instance = 0;
  vkCreateInstance(&info, 0, &instance);
  unsigned physicalDevicesCount = 0;
  vkEnumeratePhysicalDevices(instance, &physicalDevicesCount, 0);
  return physicalDevicesCount;
}
