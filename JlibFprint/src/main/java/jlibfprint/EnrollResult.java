package jlibfprint;

public class EnrollResult {

    private PrintData printData;
    private EnrollResultCode code;

    private EnrollResult(int code, PrintData printData) {
        this.code = EnrollResultCode.getValueByCode(code);
        this.printData = printData;
    }

    public PrintData getPrintData() {
        return printData;
    }

    public EnrollResultCode getCode() {
        return code;
    }

}
