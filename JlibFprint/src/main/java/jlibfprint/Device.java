package jlibfprint;

public class Device {

    private long internalPointer;
    private boolean closed = false;

    private Device() {
    }

    public native int getNumberEnrollStages();

    public native int getImageWidth();

    public native int getImageHeight();

    public void close() {
        if (!closed) {
            nativeClose();
        }
    }

    private native void nativeClose();

    public native EnrollResult enroll();

    @Override
    protected void finalize() throws Throwable {
        close();
        super.finalize();
    }

}
