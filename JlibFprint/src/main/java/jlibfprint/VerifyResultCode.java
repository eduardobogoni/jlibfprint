package jlibfprint;

public enum VerifyResultCode {

    NO_MATCH(0),
    MATCH(1),
    RETRY(100),
    RETRY_TOO_SHORT(101),
    RETRY_CENTER_FINGER(102),
    RETRY_REMOVE_FINGER(103);

    private int code;

    VerifyResultCode(int code) {
        this.code = code;
    }

    public int getCode() {
        return code;
    }

    public static VerifyResultCode getValueByCode(int code) {
        for (VerifyResultCode vr : VerifyResultCode.values()) {
            if (vr.code == code) {
                return vr;
            }
        }
        return null;
    }
}
