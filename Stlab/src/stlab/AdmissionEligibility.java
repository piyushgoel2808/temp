/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

public class AdmissionEligibility {

    public boolean isEligible(int maths, int physics, int chemistry) {

        if (maths < 60 || physics < 50 || chemistry < 50) {
            return false;
        }

        int total = maths + physics + chemistry;

        if (total >= 160 || (maths + physics) >= 120) {
            return true;
        }

        return false;
    }

    public boolean isHonors(int maths, int physics, int chemistry) {
        int total = maths + physics + chemistry;
        return isEligible(maths, physics, chemistry) && total > 225;
    }
}