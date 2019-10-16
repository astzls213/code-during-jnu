package exp2;

public class ArgsDemo {
    public static void main(String[] args){
        if(args[0].equals("-f")){
            if(args.length==3)
            {
                if(args[2].startsWith("-V"))
                    System.out.println("Options failed!");
                if(args[2].startsWith("-h"))
                    System.out.println("Options failed!");
                if(args[2].startsWith("-v"))
                    System.out.println("Others now not existed!");
            }
            else {
                if (args.length > 1 && !args[1].startsWith("-"))
                    System.out.println(args[1] + " already read!");
                else
                    System.out.println("Options failed! Requiring file name.");
            }
        }
        if(args[0].equals("-V")){
            if(args.length>1)
                System.out.println("Options failed.");
            else
                System.out.println("Version: 777");
        }
        if(args[0].equals("-h")){
            if(args.length>1)
                System.out.println("Options failed.");
            else
            {
                System.out.println("-V show version");
                System.out.println("-h show help");
                System.out.println("-f [fileName] read file");
                System.out.println("-v display other infos");
            }
        }
    }
}
