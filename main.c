#if 0
#!/bin/sh
cc main.c /usr/lib/x86_64-linux-gnu/libvulkan.so.1
./a.out
echo $?
exit 0
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
