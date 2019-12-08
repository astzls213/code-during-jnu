package exp5;
import java.io.*;
import java.util.Enumeration;
import java.util.zip.*;
public class operationForDemo3 {
    private String fileName;
    private String zipName;
    public operationForDemo3(String fileName,String zipName){
        this.fileName=fileName;
        this.zipName=zipName;
    }
    public void zip() throws Exception
    {
        ZipOutputStream out = new ZipOutputStream(new FileOutputStream(zipName));

        File sourceFile = new File(fileName);

        //调用函数
        compress(out,sourceFile,sourceFile.getName());

        out.close();
        System.out.println("压缩完成");

    }
    public void compress(ZipOutputStream out,File sourceFile,String base) throws Exception
    {
        if(sourceFile.isDirectory())
        {
            File[] flist = sourceFile.listFiles();
            if(flist.length==0)
            {
                System.out.println(base+"/");
                out.putNextEntry(new ZipEntry(base+"/"));
            }
            else
            {
                for (File file : flist) {
                    compress(out, file, base + "/" + file.getName());
                }
            }
        }
        else
        {
            out.putNextEntry(new ZipEntry(base));
            FileInputStream fos = new FileInputStream(sourceFile);
            BufferedInputStream bis = new BufferedInputStream(fos);

            int tag;
            System.out.println(base);
            while((tag=bis.read())!=-1)
            {
                out.write(tag);
            }
            bis.close();
            fos.close();
        }
    }

    public void unzip(File file,String unzippath) throws IOException {
        ZipFile zf = new ZipFile(file);
        Enumeration entries = zf.entries();
        ZipEntry entry = null;
        while (entries.hasMoreElements()) {
            entry = (ZipEntry) entries.nextElement();
            System.out.println("Unzipping: " + entry.getName());
            if (entry.isDirectory()) {
                String dirPath = unzippath + File.separator + entry.getName();
                File dir = new File(dirPath);
                dir.mkdirs();
            } else {
                InputStream is = zf.getInputStream(entry);
                // 表示文件
                File f = new File(unzippath + File.separator + entry.getName());
                //文件名
                String filename= f.getName();
                if (!f.exists()) {
                    File fileParent = f.getParentFile();
                    if(!fileParent.exists()){
                        fileParent.mkdirs();
                    }
                }
                f.createNewFile();
                // 将压缩文件内容写入到这个文件中
                FileOutputStream fos = new FileOutputStream(f);
                int count;
                byte[] buf = new byte[8192];
                while ((count = is.read(buf)) != -1) {
                    fos.write(buf, 0, count);
                }
                fos.flush();
                fos.close();
                is.close();
            }
        }
        zf.close();
    }
}
