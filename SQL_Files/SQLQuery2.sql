use BrensDenDB
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE Apartment_Crud
@Action varchar(10),
@Name varchar(100) = null,
@ApartmentId int = null,
@Address varchar(100) = null,
@Description varchar(100) = null,
@IsActive bit = false,
@Price decimal(10,2) = null,
@Size decimal(10,2) =  null,
@Bedrooms varchar(100) = null,
@Bathrooms varchar(100) = null,
@Parkings varchar(100) = null,
@UploadType varchar(100) = null,
@ImageUrl_1 varchar(MAX) = null

AS
BEGIN

SET NOCOUNT ON;
--select
if @Action='Select'
BEGIN
  Select* from dbo.APARTMENT order by ap_date DESC
END

if @Action='Select4Details'
BEGIN
  Select* from dbo.APARTMENT where ap_id = @ApartmentId
END

--insert
if @Action = 'Insert'
 BEGIN
    Insert into dbo.APARTMENT(ap_building_name,ap_num_bedrooms, ap_num_bathrooms, ap_num_parkings, ap_location, ap_des, ap_square_feet,ap_rent_amount,ap_upload_type,ap_image1,ap_date)
values(@Name,@Bedrooms, @Bathrooms,@Parkings, @Address,@Description, @Size, @Price,@UploadType, @ImageUrl_1, GETDATE())

END

--update
if @Action = 'Update'
BEGIN
  Declare @Update_image varchar(20)
  select @Update_image = (Case when @ImageUrl_1 is null then 'no' else 'yes' end)
  if @Update_image = 'no'
    BEGIN
 update dbo.APARTMENT
 SET ap_building_name=@Name, IsActive = @IsActive
 Where ap_id=@ApartmentId
end
  else
    BEGIN
 update dbo.APARTMENT
 set ap_building_name=@Name, ap_image1=@ImageUrl_1, IsActive=@IsActive
 where ap_id=@ApartmentId
end
 end

 --delete
 If @Action = 'Delete'
   Begin
      delete from dbo.APARTMENT where ap_id=@ApartmentId
   end
 
 --getBYid
 if @Action='GetById'
   BEGIN
       select * from dbo.APARTMENT where ap_id=@ApartmentId
   END

End
GO
