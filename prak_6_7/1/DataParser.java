import java.util.ArrayList;
import java.util.List;

public class DataParser {
    private static List<String> validCountryCodes = new ArrayList<String>(); // Note: Country Code mungkin saja ditambah. Format country code selalu +XX

    public DataParser() {
        validCountryCodes.add("+62");
    }

    public void addCountryCode(String code) {
        validCountryCodes.add(code);
    }

    // Return true apabila phone valid. Panjang phone number yang valid minimal 8 dan maksimal 10 angka setelah country code.
    // Apabila country code tidak ditemukan di list of validCountryCodes, throw InvalidCountryException
    // Apabila panjang nomor tidak valid, throw InvalidPhoneLengthException
    // Tips: Gunakan StringBuilder
    public boolean parsePhone(String phone) throws InvalidCountryException, InvalidPhoneLengthException {

        
        // check phone country code
        boolean countryValid = false;
        for (String cc : validCountryCodes){
            if (phone.substring(0, 3).equals(cc)) countryValid = true; 
        }
        if (!countryValid) throw new InvalidCountryException();

        // check phone length
        if (phone.length() < 11 || phone.length() > 13) throw new InvalidPhoneLengthException();

        return true;
    }   

    // Return true apabila email valid. Email yang valid adalah email dengan format *@*.*
    // A@gmail.co.com.id adalah email yang valid
    // A.B.C@mail.co adalah email yang valid
    // @gmail.com tidak valid dan akan throw InvalidEmailUserException
    // A@gmail tidak valid dan akan throw InvalidEmailDomainException
    // Algoritma akan mengecek username terlebih dahulu sebelum mengecek domain dari email
    // Dipastikan ada satu @
    public boolean parseEmail(String email) throws InvalidEmailUserException, InvalidEmailDomainException {

        // check user
        if (email.startsWith("@")) throw new InvalidEmailUserException();
        if (email.endsWith("@")) throw new InvalidEmailUserException();
        if (email.indexOf("@") != email.lastIndexOf("@")) throw new InvalidEmailUserException();

        // check domain
        String domain = email.substring(email.indexOf("@") + 1);
        if (!domain.contains(".")) throw new InvalidEmailDomainException();
        if (domain.endsWith(".")) throw new InvalidEmailDomainException();

        return true;
    }
    
}
