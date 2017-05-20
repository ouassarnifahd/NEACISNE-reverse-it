library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;


entity diviseur is
    Port ( clk : in STD_LOGIC;
           sel : out STD_LOGIC_VECTOR (1 downto 0));
end diviseur;

architecture Behavioral of diviseur is
    signal count : STD_LOGIC_VECTOR(17 downto 0);
    

begin

process(clk)
begin
    if rising_edge(clk) then
    count<=count+1;
    end if;
end process;

sel(1)<=count(17);
sel(0)<=count(16);

end Behavioral;
