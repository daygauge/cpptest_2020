package scanner;

import java.util.Arrays;

public record java12() {

    public static void main(String[] s) {
        int a[] = new int[20];
        // test1(a);
        test1_min(a);

        System.out.println(Arrays.toString(a));
        System.out.println(my_toString(a));
        // System.out.println(new String[10].length + 2);
        return;

    }

    public static int[] test1(int i[]) {
        for (int is = 0; is < i.length; is++) {
            i[is] = is;
        }
        return i;
    }

    public static int[] test1_min(int i[]) {
        for (int is = 0; is < i.length; is++) {
            i[is] = is * -1;
        }
        return i;
    }

    public static String my_toString(int num[]) {
        if (num.length == 0)
            return "[]";
        char cls[] = new char[num.length];// return char值

        char ctoss[][] = new char[num.length][];// 存储高于9的值
        int ctossintx = 0;

        // 处理3种情况，>10 <10 <0
        for (int i = 0; i < num.length; i++) {

            if (num[i] > 9) // 大于9存入*
            {
                cls[i] = '*';
                ctoss[ctossintx++] = my_toString_s(num[i]);
            } else if (num[i] < 0) // 小于0存入-
            {
                cls[i] = '-';
                if (num[i] * -1 > 9) {
                    ctoss[ctossintx++] = my_toString_s(num[i] * -1);
                } else {
                    char charls[] = new char[1];
                    charls[0] = (char) ((num[i] * -1) + 48);
                    ctoss[ctossintx++] = charls;
                }

            } else {
                cls[i] = (char) (num[i] + 48);
            }
        }

        String sls = "[";
        int slsreturnintx = 0;// ctoss数组下标
        int ctest2 = 0;
        for (char c : cls) {
            if (c == '*') {// 正数十位以上情况
                for (char ctchar : ctoss[slsreturnintx]) {
                    sls += ctchar;
                }
                slsreturnintx++;
                if (ctest2 != cls.length - 1)
                    sls += ", ";

            } else if (c == '-') {// 负数情况
                sls += '-';
                for (char ctchar : ctoss[slsreturnintx]) {
                    sls += ctchar;
                }
                slsreturnintx++;
                if (ctest2 != cls.length - 1)
                    sls += ", ";

            } else {// 普通情况
                sls += c;
                if (c != cls[cls.length - 1])
                    sls += ", ";
            }
            ctest2++;
        }
        sls += "]";
        return sls;
    }

    // 处理10以上情况
    public static char[] my_toString_s(int ils) {
        int x = my_intls(ils);
        char c[] = new char[x];
        int i = x - 1;
        while (ils > 9) {
            int a = ils % 10;
            ils /= 10;
            c[i] = (char) (a + 48);
            i--;
        }
        c[i] = (char) (ils + 48);
        return c;
    }

    public static int my_intls(int a) {
        int i = 0;
        while (a > 9) {
            a /= 10;
            i++;
        }
        return ++i;
    }

}
