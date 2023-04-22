import java.util.Collections;
import java.util.ArrayList;
import java.util.Comparator;



public class Main {

    private static class StringComparator implements Comparator<String> {

        @Override
        public int compare(String o, String p) {
            if (o.length() > p.length()) {
                return 1;
            }
            if (o.length() < p.length()) {
                return -1;
            }
            else {
                return 0;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("Sorting an ArrayList of Doubles");
        ArrayList<Double> doubles = new ArrayList<>();
        doubles.add(2.23);
        doubles.add(4.25);
        doubles.add(5.29);
        doubles.add(0.23);
        Collections.sort(doubles);
        System.out.println(doubles);


        System.out.println("Sorting an ArrayList of Strings");
        StringComparator comparator = new StringComparator();
        ArrayList<String> strings = new ArrayList<>();
        strings.add("zebra");
        strings.add("Conner");
        strings.add("Potato");
        strings.add("Zeke");
        Collections.sort(strings, comparator);
        System.out.println(strings);
    }


}

