package jlibfprint;

/**
 *
 * @author eduardo
 */
public class DiscoveredDevice {

    private long internalPointer;
    private DiscoveredDeviceList sourceList;
    
    public native int getType();

}
