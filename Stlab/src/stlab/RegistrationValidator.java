/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;


public class RegistrationValidator {

    public boolean isPageLoaded(boolean fieldsPresent) {
        return fieldsPresent;
    }

    public boolean areMandatoryFieldsMarked(boolean marked) {
        return marked;
    }

    public boolean hasButtons(boolean hasSubmit, boolean hasReset) {
        return hasSubmit && hasReset;
    }

    public boolean submitForm(String username, String password, String email) {
        return username != null && !username.isEmpty()
                && password != null && !password.isEmpty()
                && email != null && !email.isEmpty();
    }

    public boolean resetForm() {
        return true; // assume reset clears fields
    }
}