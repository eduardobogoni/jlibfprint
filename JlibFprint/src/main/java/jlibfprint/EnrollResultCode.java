package jlibfprint;

public enum EnrollResultCode {

    COMPLETE(1),
    FAIL(2),
    PASS(3),
    RETRY(100),
    RETRY_TOO_SHORT(101),
    RETRY_CENTER_FINGER(102),
    RETRY_REMOVE_FINGER(103);

    private final int code;

    EnrollResultCode(int code) {
        this.code = code;
    }

    public int getCode() {
        return code;
    }

    public static EnrollResultCode getValueByCode(int code) {
        for (EnrollResultCode vr : EnrollResultCode.values()) {
            if (vr.code == code) {
                return vr;
            }
        }
        return null;
    }

}
