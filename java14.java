package scanner;

public class java14 {

    public static void main(String[] s) {

        int num1[][] = new int[11][11];
        num1[0][1] = 1;
        num1[1][2] = 2;
        num1[1][3] = 7;
        test01(num1);
        System.out.println("=================================================");

        test01(test02rushtest01(test02(num1, 3)));
        return;
    }

    public static void test01(int num1[][]) {

        for (int nls[] : num1) {
            for (int nint : nls) {
                System.out.print(nint + " ");
            }
            System.out.println();
        }
        return;
    }

    public static int[][] test02(int num1[][], int x) {
        int num2[][] = new int[x + 1][3];
        num2[0][0] = num2[0][1] = 11;
        num2[0][2] = x;
        int num2i = 1;

        for (int i = 0; i < num1.length; i++) {
            for (int j = 0; j < num1[i].length; j++) {
                if (num1[i][j] != 0) {
                    num2[num2i][0] = i;
                    num2[num2i][1] = j;
                    num2[num2i][2] = num1[i][j];
                    num2i++;
                }
            }
        }
        test02printf(num2);
        return num2;
    }

    public static void test02printf(int numls[][]) {
        for (int i[] : numls) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println();

        }
        return;
    }

    public static int[][] test02rushtest01(int st[][]) {
        int sls[][] = new int[st[0][0]][st[0][1]];
        int bool = 1;
        for (int ist[] : st) {
            if (bool == 0 || bool-- == 0)
                sls[ist[0]][ist[1]] = ist[2];
        }

        return sls;
    }

}
