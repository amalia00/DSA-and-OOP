package dentist;
public interface Identifiable<TId>{
    public TId getID();
    public void setID(TId id);
}
