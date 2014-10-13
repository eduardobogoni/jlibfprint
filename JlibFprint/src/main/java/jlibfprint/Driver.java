package jlibfprint;

public class Driver {

    public long internalPointer;
    
    private Driver() {
    }

    public native String getName();

    public native String getFullName();

    public native int getId();
}
