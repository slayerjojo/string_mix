public class MixHelper
{
    private static String charset = "abcdefghijkmnlopqrstuvwxyz0123456789ABCDEFGHIJKMNLOPQRSTUVWXYZ";

    private static int factor(int i, int size)
    {
        return ((3 * i + 7 + (size % 2)) % charset.length());
    }

    public static String mix(String data)
    {
        String ret = new String();
        int i = 0, length = charset.length();
        for (i = 0; i < data.length(); i++)
        {
            int idx = charset.indexOf(data.charAt(i));
            if (idx < 0)
                return null;
            int pos = (idx + factor(i, data.length())) % charset.length();
            ret += charset.substring(pos, pos + 1);
        }
        return ret;
    }

    public static String restore(String data)
    {
        String ret = new String();
        int i = 0, length = charset.length();
        for (i = 0; i < data.length(); i++)
        {
            int idx = charset.indexOf(data.charAt(i));
            if (idx < 0)
                return null;
            int pos = 0;
            if (idx > factor(i, data.length()))
                pos = idx - factor(i, data.length());
            else
                pos = (length - factor(i, data.length()) + idx) % length;
            ret += charset.substring(pos, pos + 1);
        }
        return ret;
    }

    public static void main(String []args)
    {
        System.out.println("raw:" + args[0]);
        args[0] = mix(args[0]);
        System.out.println("mix:" + args[0]);
        args[0] = restore(args[0]);
        System.out.println("restore:" + args[0]);
    }
}
