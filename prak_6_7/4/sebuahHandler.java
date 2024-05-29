class SebuahHandler {
    @HttpVar(type = HttpVar.Type.Query, name = "q")
    private String q;

    @HttpVar(type = HttpVar.Type.Cookie, name = "session")
    private String ses;
  
    @HttpVar(type = HttpVar.Type.Header, name = "Authorization")
    private void initToken(String auth) {
        System.out.println("Header: " + auth);
    }
    @HttpVar(type = HttpVar.Type.Query, name = "q")
    private void initToken2(String auth) {
        System.out.println("Query: " + auth);
    }
    @HttpVar(type = HttpVar.Type.Body, name = "name")
    private void initToken3(String auth) {
        System.out.println("Body: " + auth);
    }
    // @HttpVar(type = HttpVar.Type.Header, name = "Bearer 123")
    // private void initToken1(String auth) {
    //     System.out.println("Token: " + auth);
    // }

    public void print() {
        System.out.println("q: " + q);
        System.out.println("ses: " + ses);
    }
}