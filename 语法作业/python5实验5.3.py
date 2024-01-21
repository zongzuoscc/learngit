def check_beads(seller, buyer):
    counts = {}
    
    # 统计卖家的珠串中各个颜色的个数
    for bead in seller:
        if bead in counts:
            counts[bead] += 1
        else:
            counts[bead] = 1
    
    required_count = 0
    
    # 统计买家的珠串中各个颜色的个数以及总数
    for bead in buyer:
        if bead in counts and counts[bead] > 0:
            counts[bead] -= 1
        else:
            required_count += 1
    
    # 判断是否可以买，并输出
    if required_count == 0:
        extra = len(seller) - len(buyer)
        return "Yes", extra
    else:
        return "No", required_count


seller = input()
buyer = input()

result, count = check_beads(seller, buyer)
print(result, count)