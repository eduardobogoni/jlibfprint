package jlibfprint;

public class PrintData {

    private long internalPointer;

    private native void free();

    @Override
    protected void finalize() throws Throwable {
        free();
        super.finalize(); //To change body of generated methods, choose Tools | Templates.
    }

}
