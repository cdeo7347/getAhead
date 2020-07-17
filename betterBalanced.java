import java.util.Stack;

public class BalancedParentheses
{
   public static int longestBalanced(String str) 
   {
     // initializes max string length
     int maxstr = 0;
     int current_size = 0;
     int flag = 0;
     int possible = 0;
     Stack leftParenthese = new Stack();
     for (int i = 0; i < str.length(); i++) 
     {
       char currentChar = str.charAt(i);
       if (currentChar == '(')
       {
         if (!leftParenthese.empty() && flag > 0)
         {
           if (maxstr < possible)
                maxstr = possible;
            flag--;
            possible = 0;
         }
         leftParenthese.push('(');
       } 
       else if (!leftParenthese.empty() && currentChar == ')')
       {
         leftParenthese.pop();
         current_size += 2;
         possible += 2;
         flag++;
       }
       if (leftParenthese.empty())
       {
         if (current_size > maxstr)
            maxstr = current_size;
          current_size = 0;
       }
     }
     if (!leftParenthese.empty())
     {
       if (maxstr < possible)
          maxstr = possible;
     }
     return maxstr;
   }
}
    
