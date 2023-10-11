# Nostalgia
Bài làm từ những buổi livestream mà mình thử giải đề thi của các học phần mình đã từng học ^^

**Link youtube**: https://youtube.com/@motherofsuper-coding

**Link facebook**: https://www.facebook.com/naturemother/

## Notes
### KTLT (22TNT1TN) (2022-2023)
**Link livestream**:
- Part 1: https://youtu.be/NlrWzfNn6lA
- Part 2 (Câu 3 và Câu 4): https://youtu.be/HZi7Y9EpB4M

#### Câu 3
- Câu lệnh để hủy mảng cần sử dụng dạng **delete[]** thay vì chỉ **delete**

#### Câu 4
- Có 1 cách tối ưu hơn để bỏ qua các Data Blocks là xài hàm **in.seekg** (Nếu xài cách này thì cần **cẩn thận** trong việc tính toán phần size sẽ bỏ qua)
- Nên có phần kiểm tra xem file lúc mở có valid để đọc hay không (Kiểm tra **if (!in)** thì thông báo lỗi và return)

### NMLT (CNTN) (2022-2023)
**Một quan sát thú vị dành cho Câu 2**

Có 1 cách đơn giản hơn rất nhiều xDD Đó là:
- So sánh theo từng kí tự từ đầu của cả 2 chuỗi
- Nếu gặp kí tự nào khác nhau thì mình sẽ dừng so sánh và đếm số dấu '/' từ đó cho đến cuối chuỗi 1 và chuỗi 2
- Cộng số dấu '/' lại sẽ cho ta kết quả đúng

**Link livestream**: https://youtu.be/1qQk1IIv2L0

**Link livestream fix code Câu 2 & Câu 3**: https://youtu.be/umBT1MOMV7g

#### Câu 2
- Mình có fix dành cho trường hợp có thể có các thư mục cùng tên nhau

#### Câu 3
- Mình có fix dành cho một số edge cases
- Update ý tưởng thuật toán theo code đã fix

### OOP (2022-2023)
**Link livestream**: https://youtu.be/f0dgv0jJ8ZU

#### Câu 3
- Mình có minor fix cho **Class Diagram** về mối quan hệ **Composition** từ **Project** tới **Fund** (Chứ không còn là từ **Project** tới **MoneyFund**)
- Xóa bớt method **getName()** thừa trong code của class **MoneyFund** (Đã có từ class **Fund**)
- Sửa kí hiệu **Multiplicity** trong **Class Diagram** từ 0..n thành 0..* (Kí hiệu chuẩn của UML)