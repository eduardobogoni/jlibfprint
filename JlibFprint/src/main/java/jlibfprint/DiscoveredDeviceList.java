package jlibfprint;

public class DiscoveredDeviceList {

    private long internalPointer;
    private DiscoveredDevice[] discoveredDevices;

    public DiscoveredDevice[] getDiscoveredDevices() {
        return discoveredDevices;
    }
}
