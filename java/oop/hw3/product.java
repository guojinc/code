package java.oop.hw3;

import java.sql.Date;

/**
 * product
 */
public class product {
    private String code;
    private String description;
    private double price;
    private Date productionDate;
    private String shelfLife;

    /**
     * @param code          the code
     * @param description   the description
     * @param price         the price
     * @param productionDate the production date
     * @param shelfLife     the shelf life
     */
    public product(String code, String description, double price, Date productionDate, String shelfLife) {
        this.code = code;
        this.description = description;
        this.price = price;
        this.productionDate = productionDate;
        this.shelfLife = shelfLife;
    }

    /**
     * @return the code
     */
    public String getCode() {
        return this.code;
    }

    /**
     * @return the description
     */
    public String getDescription() {
        return this.description;
    }

    /**
     * @return the price
     */
    public double getPrice() {
        return this.price;
    }

    /**
     * @return the productionDate
     */
    public Date getProductionDate() {
        return this.productionDate;
    }

    /**
     * @return the shelfLife
     */
    public String getShelfLife() {
        return this.shelfLife;
    }

    /**
     * @param object the other object
     */
    public boolean equals(object Object)
    {
        if (this == Object) {
            return true;
        }
        if (Object == null) {
            return false;
        }
        if (getClass() != Object.getClass()) {
            return false;
        }
        product other = (product) Object;
        if (code == null) {
            if (other.code != null) {
                return false;
            }
        } else if (!code.equals(other.code)) {
            return false;
        }
        return true;
    }

    /**
     * @return the string representation of the object
     */
    public String toString() {
        return "Product [code=" + code + ", description=" + description + ", price=" + price + ", productionDate="
                + productionDate + ", shelfLife=" + shelfLife + "]";
    }
}