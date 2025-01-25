import java.io.*;

class MultTable
{
    public static void main(String args[])
    {
        int i,j;
        try{
            BufferedWriter writer=new BufferedWriter(new FileWriter("Multiplication_Table.txt"));
            for(i=1;i<=10;i++)
            {
                for(j=1;j<=10;j++)
                {
                    writer.write(i+"x"+j+"="+i*j+"\n");
                }
                writer.newLine();
            }
            writer.close();
        }catch(Exception e)
        {
            System.out.println(e);
        }
    }
}