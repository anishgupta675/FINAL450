import java.util.*;
 
class GFG{
     



static int internalSearch(String needle, int row,
                          int col, String hay[],
                          int row_max, int col_max,
                          int xx)
{
    int found = 0;
     
    if (row >= 0 && row <= row_max && col >= 0 &&
        col <= col_max && xx < needle.length() &&
        needle.charAt(xx) == hay[row].charAt(col))
    {
        char match = needle.charAt(xx);
        xx += 1;
 
        hay[row] = hay[row].substring(0, col) + "0" +
                   hay[row].substring(col + 1);
 
        if (xx == needle.length())
        {
            found = 1;
        }
        else
        {
             
            
            
            found += internalSearch(needle, row,
                                    col + 1, hay,
                                    row_max, col_max,xx);
            found += internalSearch(needle, row, col - 1,
                                    hay, row_max, col_max,xx);
            found += internalSearch(needle, row + 1, col,
                                    hay, row_max, col_max,xx);
            found += internalSearch(needle, row - 1, col,
                                    hay, row_max, col_max,xx);
        }
         
        hay[row] = hay[row].substring(0, col) +
           match + hay[row].substring(col + 1);
    }
    return found;
}
 

static int searchString(String needle, int row, int col,
                        String str[], int row_count,
                                      int col_count)
{
    int found = 0;
    int r, c;
 
    for(r = 0; r < row_count; ++r)
    {
        for(c = 0; c < col_count; ++c)
        {
            found += internalSearch(needle, r, c, str,
                                    row_count - 1,
                                    col_count - 1, 0);
        }
    }
    return found;
}
 

public static void main(String args[])
{
    String needle = "MAGIC";
    String input[] = { "BBABBM", "CBMBBA",
                       "IBABBG", "GOZBBI",
                       "ABBBBC", "MCIGAM" };
    String str[] = new String[input.length];
    int i;
    for(i = 0; i < input.length; ++i)
    {
        str[i] = input[i];
    }
 
    System.out.println("count: " +
              searchString(needle, 0, 0, str,
                           str.length,
                           str[0].length()));
}
}