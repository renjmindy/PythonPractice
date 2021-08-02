-- Challenge 2: Analyze profitability
-- (1) Retrieve the cost, list price, and average selling price for each product.
-- (2) Retrieve products that have an average selling price that is lower than the cost.
-- SELECT p.ProductID, p.Name, p.StandardCost, p.ListPrice, (
--                                                          SELECT ISNULL(AVG(s.UnitPrice), '') 
--                                                          FROM SalesLT.SalesOrderDetail AS s
--                                                          WHERE p.ProductID = s.ProductID  
--                                                         ) AS AveSoldPrice
-- FROM SalesLT.Product AS p
-- WHERE p.StandardCost > (
--                        SELECT AVG(s.UnitPrice)
--                        FROM SalesLT.SalesOrderDetail AS s
--                        WHERE p.ProductID = s.ProductID  
--                       ) 
-- ORDER BY p.ProductID
-- SELECT p.ProductID, p.Name, p.ListPrice, (
--                                           SELECT ISNULL(AVG(s.UnitPrice), '')
--                                           FROM SalesLT.SalesOrderDetail AS s
--                                           WHERE p.ProductID = s.ProductID  
--                                          ) AS AveSoldPrice
-- FROM SalesLT.Product AS p
-- ORDER BY p.ProductID

-- Challenge 1: Retrieve product price information
-- (1) Retrieve products whose list price is higher than the average unit price.
-- (2) Retrieve Products with a list price of 100 or more that have been sold for less than 100.
-- SELECT *
-- SELECT ProductID, Name, ListPrice
-- FROM SalesLT.Product
-- FROM SalesLT.SalesOrderDetail
-- WHERE ListPrice >= 100 AND ProductID IN (
--                                         SELECT ProductID
--                                         FROM SalesLT.SalesOrderDetail
--                                         WHERE UnitPrice < 100
--                                        )
-- WHERE ListPrice > (
--                   SELECT AVG(UnitPrice)
--                   FROM SalesLT.SalesOrderDetail 
--                  )
-- ORDER BY ProductID