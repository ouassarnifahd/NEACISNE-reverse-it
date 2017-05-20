library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- BLOCK: diviseur --

entity diviseur is
  port ( clk : in STD_LOGIC;
         sel : out STD_LOGIC_VECTOR (1 downto 0));
end diviseur;

architecture behavioral of diviseur is
    signal count : STD_LOGIC_VECTOR (17 downto 0);

begin

SYNC : process(clk)
begin
    if rising_edge(clk) then
        count <= count + 1;
    end if;
end process;

sel(0) <= count(17);
sel(1) <= count(16);

end architecture;
