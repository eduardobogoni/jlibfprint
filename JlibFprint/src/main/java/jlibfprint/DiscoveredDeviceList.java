package jlibfprint;

public class DiscoveredDeviceList {

    private long internalPointer;
    private DiscoveredDevice[] discoveredDevices;

    private DiscoveredDeviceList() {
    }

    public DiscoveredDevice[] getDiscoveredDevices() {
        return discoveredDevices;
    }
}
