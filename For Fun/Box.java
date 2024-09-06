class Box
{
    int length;
    int width;
    int height;
    void Box(int length, int width, int height)
    {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    public static void main()
    {
        Box myBox = new Box(10,15,20);
        System.out.println("Length:"+myBox.length);
        System.out.println("Width:"+myBox.width);
        System.out.println("Height:"+myBox.height);
    }
}