package dentist;


public class Patient implements Identifiable<Integer> {
    private int id;
    private String name,address,phoneNr;
    public Patient()
    {
        id=0;
        name="";
        address="";
        phoneNr="";
    }
    public Patient(Integer id,String name,String address,String phoneNr) {
        this.id=id;
        this.name = name;
        this.address = address;
        this.phoneNr = phoneNr;
    }
    public Patient(String name,String address,String phoneNr) {
        this.name = name;
        this.address = address;
        this.phoneNr = phoneNr;
    }
    @Override
    public Integer getID() {
        return id;
    }
    @Override
    public void setID(Integer id) {
        this.id = id;
    }
    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name=name;
    }
    public String getAddress()
    {
        return address;
    }

    public void setAddress(String address)
    {
        this.address=address;
    }
    public String getPhoneNumber()
    {
        return phoneNr;
    }

    public void setPhoneNumber(String phoneNumber)
    {
        this.phoneNr=phoneNumber;
    }
    @Override
    public String toString() {
        return "Patient{" +
                "id=" + id +
                ", name=" + name +
                ", address='" + address + '\'' +
                ", phoneNr=" + phoneNr +
                '}';
    }
    @Override
    public boolean equals(Object obj)
    {
        if(obj instanceof Patient)
        {
            Patient p=(Patient) obj;
            return this.id==p.id;
        }
        return false;



    }
}