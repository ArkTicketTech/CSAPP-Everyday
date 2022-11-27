# \## 11-05-02 URL在web请求中对客户端和服务端的作用

例如：URL

“http://bluef ish.ics.cs.emu.edu:8000/cgi-bin/adder?15000&213” ([pdf](zotero://open-pdf/library/items/QQZJIDJ4?page=701))

**客户端使用**前缀”http://bluef ish.ics.cs.emu.edu:8000“来决定与哪类服务器联系，服务器在哪里，以及它监听的端口号是多少。

**服务端**使用后缀“/cgi-bin/adder”来发现在它文件系统中的文件，并确定请求的是静态内容还是动态内容。 8000与cgi-bin之间的“/”不表示linux的根目录，而是表示请求内容类型的主目录。

客户端使用**域名地址**来确定请求服务器的所在地址，端口号。  **域名地址后的文件名及参数**是服务端需要的，来判断返回的是动态内容还是静态内容。
