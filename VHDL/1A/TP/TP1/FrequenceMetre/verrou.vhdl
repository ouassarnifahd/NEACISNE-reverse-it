library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- BLOCK: verrou --

entity verrou is
    port ( clk : in STD_LOGIC;
           verr : in STD_LOGIC;
           freq : in STD_LOGIC_VECTOR(15 downto 0);
           freq_verr : out STD_LOGIC_VECTOR(15 downto 0));
end verrou;

architecture behavioral of verrou is

begin

SYNC : process(clk)
begin
    if rising_edge(clk) then
        if verr='1' then
            freq_verr <= freq;
        end if;
    end if;
end process;



end behavioral;
